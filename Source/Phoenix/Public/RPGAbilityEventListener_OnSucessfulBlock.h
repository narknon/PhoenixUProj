#pragma once
#include "CoreMinimal.h"
#include "RPGAbilityEventListener.h"
#include "RPGAbilityEventListener_OnSucessfulBlock.generated.h"

class ABiped_Player;

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_OnSucessfulBlock : public URPGAbilityEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ABiped_Player* BipedPlayer;
    
public:
    URPGAbilityEventListener_OnSucessfulBlock();
};

