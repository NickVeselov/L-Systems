// Fill out your copyright notice in the Description page of Project Settings.

#include "LSystems.h"
#include "ConfigFileReader.h"
#include "Regex.h"

ConfigFileReader::ConfigFileReader()
{
}

ConfigFileReader::~ConfigFileReader()
{
}

bool ConfigFileReader::OpenFile(FString Path)
{
	TArray<FString> FileContent;
	FString filedir(FPaths::GameDir() + Path);
	FFileHelper::LoadANSITextFileToStrings(*filedir, NULL, FileContent);

	if (FileContent.Num() < 6)
		return false;

	FRegexPattern Pattern(TEXT("^(?!.*(Variables:))"));
	FRegexMatcher RegEx(Pattern, FileContent[0]);

	int a = 5;



	//TArray<FString> temp;
	//FileContent[1].ParseIntoArrayWS(temp);
	//for (FString s : temp) {
	//	variables.Add(s[0]); // not sure if it runs poperly
	//}

	//start_variable = FileContent[3][0];

	//roll_angle = FCString::Atof(*FileContent[5]);

	//for (int i = 7; i < FileContent.Num(); i++) {
	//	FileContent[i].ParseIntoArrayWS(temp);
	//	//print (TEXT ("Rule Line Dump: "), *FileContent[i]);
	//	if (temp.Num() == 0) {
	//		break;
	//	}
	//	rules.Add(temp[0][0], temp[2]);
	//}
	return true;
}
