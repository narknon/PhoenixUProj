#pragma once
#include "CoreMinimal.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_MultiFX2.generated.h"

class UMultiFX2_Base;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class URPGTriggerEffect_MultiFX2 : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FX2;
    
public:
    URPGTriggerEffect_MultiFX2();
};

