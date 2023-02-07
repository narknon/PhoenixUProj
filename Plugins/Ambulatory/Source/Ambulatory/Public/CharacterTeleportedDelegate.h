#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "CharacterTeleportedDelegate.generated.h"

class AAmbulatory_Character;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCharacterTeleported, AAmbulatory_Character*, TeleportedCharacter, FVector, AmountDisplaced, FRotator, AmountRotated);

