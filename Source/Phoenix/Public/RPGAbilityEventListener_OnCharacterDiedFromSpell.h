#pragma once
#include "CoreMinimal.h"
#include "RPGAbilityEventListener_OnCharacterDied.h"
#include "RPGAbilityEventListener_OnCharacterDiedFromSpell.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_OnCharacterDiedFromSpell : public URPGAbilityEventListener_OnCharacterDied {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpellGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpellName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TargetIsPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TargetIsTeammate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TargetIsEnemy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TargetIsNeutral;
    
public:
    URPGAbilityEventListener_OnCharacterDiedFromSpell();
};

