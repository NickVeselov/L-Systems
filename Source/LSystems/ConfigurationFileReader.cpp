// Fill out your copyright notice in the Description page of Project Settings.

#include "LSystems.h"
#include "ConfigurationFileReader.h"
#include "Regex.h"

// Sets default values
AConfigurationFileReader::AConfigurationFileReader()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AConfigurationFileReader::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConfigurationFileReader::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool AConfigurationFileReader::OpenFile(FString Path)
{
	TArray<FString> FileContent;
	FString filedir(FPaths::GameDir() + Path);
	FFileHelper::LoadANSITextFileToStrings(*filedir, NULL, FileContent);

	if (FileContent.Num() < 7)
		return false;

	// First line
	if (FileContent[0].Len() < 12)
		return false;

	FirstVariable = "";
	SecondVariable = "";

	FirstVariable.AppendChar(FileContent[0][11]);
	if (FileContent[0].Len() > 12)
	{
		SecondVariable.AppendChar(FileContent[0][13]);
		OneVariable = false;
	}
	else
		OneVariable = true;


	//Second line
	if (FileContent[1].Len() < 8)
		return false;
	
	Axiom = FileContent[1].Mid(7);

	// Third line
	if (FileContent[2].Len() < 8)
		return false;

	int from, to;
	FString substring;

	from = FileContent[2].Find("->") + 2;
	if (from == -1)
		return false;

	substring = FileContent[2].Mid(from);

	if (OneVariable)
		to = substring.Len();
	else if (!substring.FindChar(' ', to))
		return false;

	FirstRule = substring.Mid(0, to);
	if (!OneVariable)
	{
		substring = substring.Mid(to);

		from = substring.Find("->") + 2;
		if (from == -1)
			return false;

		SecondRule = substring.Mid(from);
	}
	//Fourth line
	if (FileContent[3].Len() < 8)
		return false;

	FileContent[3].FindChar(' ', from);
	Angle = FCString::Atof(*FileContent[3].Mid(from));

	//Fifth line
	if (FileContent[4].Len() < 9)
		return false;

	FileContent[4].FindChar(' ', from);
	Length = FCString::Atof(*FileContent[4].Mid(from));

	//Sixth line
	if (FileContent[5].Len() < 14)
		return false;

	FileContent[5].FindChar(' ', from);
	Generations = FCString::Atoi(*FileContent[5].Mid(from));
	
	//Seventh line
	if (FileContent[6].Len() < 10)
		return false;

	if (FileContent[6][9] == '+')
		FirstVariableRespondsForDrawing = true;
	else
		FirstVariableRespondsForDrawing = false;
	if (OneVariable)
	{
		SecondVariableRespondsForDrawing = false;
	}
	else
	{
		if (FileContent[6][11] == '+')
			SecondVariableRespondsForDrawing = true;
		else
			SecondVariableRespondsForDrawing = false;
	}
	return true;
}

