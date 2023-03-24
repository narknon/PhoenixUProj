#pragma once
#include "CoreMinimal.h"
#include "SpellTool.h"
#include "DeathlyHallowsCloakTool.generated.h"

class AActor;
class UMaterialInterface;
class UMultiFX2_Base;

UCLASS(Blueprintable)
class ADeathlyHallowsCloakTool : public ASpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DisillusionmentMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> DisillusionmentFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSlowWalk;
    
    ADeathlyHallowsCloakTool(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDisillusionmentStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDisillusionmentEnd();
    
protected:
    UFUNCTION(BlueprintCallable)
    void CasterHealthZero(AActor* InActor);
    
};

