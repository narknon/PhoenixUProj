#pragma once
#include "CoreMinimal.h"
#include "RPGAbilityEventListener.h"
#include "RPGAbilityEventListener_OnBreed.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_OnBreed : public URPGAbilityEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxTier;
    
public:
    URPGAbilityEventListener_OnBreed();
};

