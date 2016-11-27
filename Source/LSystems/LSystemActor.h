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

	//TreeStructure *Tree;

public:

	//Number of iterations
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		int	Generations = 3;

	//Letter for the first variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		FString FirstVariable = "X";

	//Letter for the second variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		FString SecondVariable = "F";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		FString Start = "X";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		FString First_Rule = "F-[[X]+X]+F[+FX]-X";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LSystem)
		FString Second_Rule = "FF";

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
		UStaticMeshComponent *PerformTransformation(FString symbol, UStaticMeshComponent *Turtle);

};
