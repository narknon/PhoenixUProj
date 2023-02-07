#pragma once
#include "CoreMinimal.h"
#include "GameplayPropertyMod.h"
#include "ModFloatSettings.h"
#include "ModIntSettings.h"
#include "GameplayPropertyModNumeric.generated.h"

UCLASS(Blueprintable)
class GAMEPLAYMODS_API UGameplayPropertyModNumeric : public UGameplayPropertyMod {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FModFloatSettings FloatSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FModIntSettings IntSettings;
    
    UGameplayPropertyModNumeric();
};

