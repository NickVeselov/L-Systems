// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class LSYSTEMS_API ConfigFileReader
{
public:
	ConfigFileReader();
	~ConfigFileReader();

	//Letter for the first variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemVocabulary)
		FString FirstVariable;

	//Letter for the second variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemVocabulary)
		FString SecondVariable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemRules)
		FString Axiom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemRules)
		FString FirstRule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemRules)
		FString SecondRule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		int	Generations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemRules)
		bool FirstVariableRespondsForDrawing = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemRules)
		bool SecondVariableRespondsForDrawing = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemGraphics)
		float Angle = 25;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemGraphics)
		float Length = 40;

	UFUNCTION(BlueprintCallable, Category = FileManager)
	bool OpenFile(FString Path);
};
