#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Components/SplineComponent.h"
#include "OnMercunaSplineUpdatedDelegate.h"
#include "MercunaSpline.generated.h"

UCLASS(Blueprintable)
class MERCUNA_API UMercunaSpline : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMercunaSplineUpdated SplineUpdated;
    
    UMercunaSpline();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsValid() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReady() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPartial() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FSplinePoint> GetSplinePoints() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetPathPoint(int32 I) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumPathPoints() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLength() const;
    
};

