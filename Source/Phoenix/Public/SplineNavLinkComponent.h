#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OdcNavLinkComponent.h"
#include "SplineNavLinkComponent.generated.h"

class USplineComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USplineNavLinkComponent : public UOdcNavLinkComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SplineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector SplineLinkStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector SplineLinkEnd;
    
public:
    USplineNavLinkComponent();
protected:
    UFUNCTION(BlueprintCallable)
    void RegisterNavLink();
    
};

