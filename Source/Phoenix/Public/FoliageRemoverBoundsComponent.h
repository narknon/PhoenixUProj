#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "FoliageRemoverBoundsComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UFoliageRemoverBoundsComponent : public UBoxComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanBeActivated;
    
public:
    UFoliageRemoverBoundsComponent();
    UFUNCTION(BlueprintCallable)
    void RemoveVegetationInsideBounds();
    
};

