#pragma once
#include "CoreMinimal.h"
#include "CharacterLightRigAdjustmentsName.generated.h"

USTRUCT(BlueprintType)
struct FCharacterLightRigAdjustmentsName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    RENDERSETTINGS_API FCharacterLightRigAdjustmentsName();
};

