#pragma once
#include "CoreMinimal.h"
#include "ModSettingsNumeric.h"
#include "ModIntSettings.generated.h"

USTRUCT(BlueprintType)
struct FModIntSettings : public FModSettingsNumeric {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FixedAmount;
    
    GAMEPLAYMODS_API FModIntSettings();
};

