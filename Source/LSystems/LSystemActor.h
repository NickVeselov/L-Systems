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

public:

	//Number of iterations
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		int	Generations = 1;

	//Letter for the first variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		FString FirstVariable = "A";

	//Letter for the second variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		FString SecondVariable = "B";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		FString Start = "B";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		FString First_Rule = "AA";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		FString Second_Rule = "AA-[[AB]+AB]+A[+AB]-B";

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = LSystem)
		FString EvolvedLSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		bool FirstVariableRespondsForDrawing = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		bool SecondVariableRespondsForDrawing = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		float Angle = 25;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		float Length = 20;


	// Sets default values for this actor's properties
	ALSystemActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = Lsystem)
		UStaticMeshComponent *PerformTransformation(FString symbol, UStaticMeshComponent *Turtle, bool DrawDebugSprehes);

	UFUNCTION(BlueprintCallable, Category = LSystem)
		bool DrawingRequired(FString symbol);

	//UFUNCTION(BlueprintCallable, Category = LSystem)
	//	TArray<FTransform>
};
