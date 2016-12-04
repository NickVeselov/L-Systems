// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ConfigurationFileReader.generated.h"

UCLASS()
class LSYSTEMS_API AConfigurationFileReader : public AActor
{
	GENERATED_BODY()
		bool OneVariable;
public:	
	// Sets default values for this actor's properties
	AConfigurationFileReader();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	//Letter for the first variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FileManager)
		FString FirstVariable;

	//Letter for the second variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FileManager)
		FString SecondVariable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FileManager)
		FString Axiom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FileManager)
		FString FirstRule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FileManager)
		FString SecondRule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FileManager)
		int	Generations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FileManager)
		bool FirstVariableRespondsForDrawing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FileManager)
		bool SecondVariableRespondsForDrawing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FileManager)
		float Angle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FileManager)
		float Length;

	UFUNCTION(BlueprintCallable, Category = FileManager)
		bool OpenFile(FString Path);

};
