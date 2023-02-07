#pragma once
#include "CoreMinimal.h"
#include "RPGAbilityEventListener.h"
#include "SocialSemanticIDs.h"
#include "RPGAbilityEventListener_OnSpellCast.generated.h"

class ASpellTool;
class AWandTool;

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_OnSpellCast : public URPGAbilityEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckSpellGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<SocialSemanticIDs> SpellGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpellName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bListenToPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AWandTool* Wand;
    
public:
    URPGAbilityEventListener_OnSpellCast();
protected:
    UFUNCTION(BlueprintCallable)
    void OnSpellCast(ASpellTool* SpellTool);
    
};

