#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPC_Spline.generated.h"

class UArrowComponent;
class USplineComponent;

UCLASS(Blueprintable)
class ANPC_Spline : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDrawUpArrows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SplineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UArrowComponent*> PointUpArrows;
    
    ANPC_Spline();
};

