#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FireOnceSpellTool.h"
#include "FlipendoLevelData.h"
#include "Templates/SubclassOf.h"
#include "FlipendoSpellTool.generated.h"

class AActor;
class AMunitionType_Base;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class AFlipendoSpellTool : public AFireOnceSpellTool {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFlipendoLevelData> LevelDataArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CharacterImpulseScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> AOEMunition;
    
public:
    AFlipendoSpellTool();
    UFUNCTION(BlueprintCallable)
    void FlipTarget(AActor* InTargetActor, UPrimitiveComponent* InTargetComp, const FVector& ImpactLocation);
    
};

