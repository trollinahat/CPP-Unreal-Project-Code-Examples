// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThirdPerson_GameGameMode.h"
#include "ThirdPerson_GameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AThirdPerson_GameGameMode::AThirdPerson_GameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
