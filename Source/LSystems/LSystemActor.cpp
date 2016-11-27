// Fill out your copyright notice in the Description page of Project Settings.

#include "LSystems.h"
#include "LSystemActor.h"


// Sets default values
ALSystemActor::ALSystemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALSystemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALSystemActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

