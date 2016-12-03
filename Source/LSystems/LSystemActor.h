// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TreeStructure.h"
#include "GameFramework/Actor.h"
#include "LSystemActor.generated.h"

UCLASS()
class LSYSTEMS_API ALSystemActor : public AActor
{
	GENERATED_BODY()

		virtual void OnConstruction(const FTransform& Transform) override;

	TreeStructure Tree;

	TArray<FTransform> TreeBranches;

	void PerformTransformation(TCHAR symbol);

	FVector TurtlePosition;
	FVector TurtleDirection;

	void Clear();

public:

	//Number of iterations
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		int	Generations = 3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = LSystem)
		FString EvolvedLSystem;

	//Letter for the first variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemVocabulary)
		FString FirstVariable = "X";

	//Letter for the second variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemVocabulary)
		FString SecondVariable = "F";

	//"Right" rotation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemVocabulary)
		FString CWRotationSymbol = "+";

	//"Left" rotation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemVocabulary)
		FString CCWRotationSymbol = "-";

	//New branch symbol
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemVocabulary)
		FString NewBranchSymbol = "[";

	//New branch symbol
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemVocabulary)
		FString EndBranchSymbol = "]";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemRules)
		FString Start = "X";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemRules)
		FString First_Rule = "F-[[X]+X]+F[+FX]-X";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemRules)
		FString Second_Rule = "FF";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemRules)
		bool FirstVariableRespondsForDrawing = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemRules)
		bool SecondVariableRespondsForDrawing = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemGraphics)
		float Angle = 25;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemGraphics)
		float Length = 40;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemGraphics)
		float InitialScale = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystemGraphics)
		float ScaleStep = 0.2f;

	// Sets default values for this actor's properties
	ALSystemActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = LSystem)
		void CreateTreeStructure();

	//UFUNCTION(BlueprintCallable, Category = LSystem)

	UFUNCTION(BlueprintCallable, Category = LSystem)
		int GetNumberOfBranches();

	UFUNCTION(BlueprintCallable, Category = LSystem)
		TArray<FVector> GetBranchCoordinates(int i);

	UFUNCTION(BlueprintCallable, Category = LSystem)
		float GetStartScale(int i);

	UFUNCTION(BlueprintCallable, Category = LSystem)
		float GetEndScale(int i);

	UFUNCTION(BlueprintCallable, Category = LSystem)
		FVector GetBranchDirection(int i);

	UFUNCTION(BlueprintCallable, Category = LSystem)
		void Init();
};
