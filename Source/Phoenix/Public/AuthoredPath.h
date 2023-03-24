#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuthoredPath.generated.h"

class USplineComponent;

UCLASS(Blueprintable)
class AAuthoredPath : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* PathComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SnapDistance;
    
    AAuthoredPath(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SnapPoints();
    
    UFUNCTION(BlueprintCallable)
    void ReversePoints();
    
};

