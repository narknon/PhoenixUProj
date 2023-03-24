#pragma once
#include "CoreMinimal.h"
#include "FireOnceSpellTool.h"
#include "ReparoMaximaSpellTool.generated.h"

class UActorComponent;
class UMultiFX2_Base;

UCLASS(Blueprintable)
class AReparoMaximaSpellTool : public AFireOnceSpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> RestoreLocationFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FailSafeTime;
    
    AReparoMaximaSpellTool(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ARepairComplete(UActorComponent* Comp);
    
};

