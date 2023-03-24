#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "BroomSpline.generated.h"

class USplineComponent;

UCLASS(Blueprintable)
class ABroomSpline : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* Spline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<AActor> SplineToCopy;
    
    ABroomSpline(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void GetSplinePointWorldPositions(TArray<FVector>& OutSplinePathPoints);
    
    UFUNCTION(BlueprintCallable)
    void CopySelectedSpline();
    
};

