#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FootPlantOccurredDelegate.h"
#include "FootPlantEffects.generated.h"

class UDataTable;
class UParticleSystem;

UCLASS(Blueprintable, EditInlineNew)
class AMBULATORY_API UFootPlantEffects : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFootPlantOccurred FootPlantOccurredDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* SurfaceTypeToVFXTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* TestVFX;
    
public:
    UFootPlantEffects();
};

