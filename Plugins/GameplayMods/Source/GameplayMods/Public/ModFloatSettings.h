#pragma once
#include "CoreMinimal.h"
#include "ModSettingsNumeric.h"
#include "ModFloatSettings.generated.h"

USTRUCT(BlueprintType)
struct FModFloatSettings : public FModSettingsNumeric {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FixedAmount;
    
    GAMEPLAYMODS_API FModFloatSettings();
};

