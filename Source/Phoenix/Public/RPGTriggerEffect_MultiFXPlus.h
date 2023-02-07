#pragma once
#include "CoreMinimal.h"
#include "MultiFXPlus.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_MultiFXPlus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_MultiFXPlus : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFXPlus FXData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFXPlus ActivateFx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFXPlus DeactivateFX;
    
public:
    URPGTriggerEffect_MultiFXPlus();
};

