#pragma once
#include "CoreMinimal.h"
#include "MercunaMoveRequest.h"
#include "MercunaNavigationComponent.h"
#include "IcarusNavigationComponent.generated.h"

class UMercunaPath;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ICARUSRUNTIME_API UIcarusNavigationComponent : public UMercunaNavigationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurningCircleLookAheadTime;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMercunaMoveRequest OriginalMoveRequest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMercunaPath* CurrentPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMercunaPath* NewPath;
    
public:
    UIcarusNavigationComponent();
    UFUNCTION(BlueprintCallable)
    void SetUseTurnSmoothing(bool bInUseTurnSmoothing);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetUseTurnSmoothing() const;
    
};

