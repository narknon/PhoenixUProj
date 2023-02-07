#pragma once
#include "CoreMinimal.h"
#include "Ambulatory_Character.h"
#include "TombProtectorSwordCharacter.generated.h"

class AActor;

UCLASS(Blueprintable)
class ATombProtectorSwordCharacter : public AAmbulatory_Character {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* TombProtector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Player;
    
    ATombProtectorSwordCharacter();
};

