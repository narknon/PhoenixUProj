#pragma once
#include "CoreMinimal.h"
#include "ELevelComparison.h"
#include "RPGAbilityEventListener.h"
#include "RPGAbilityEventListener_OnCharacterDied.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_OnCharacterDied : public URPGAbilityEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKillInstigatorMustBeAbilityOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELevelComparison LevelComparison;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelDifference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumDistance;
    
public:
    URPGAbilityEventListener_OnCharacterDied();
};

