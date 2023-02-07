#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ECameraStackSplineType.h"
#include "CameraStackSplineActor.generated.h"

class ACameraStackSplineActor;
class USplineComponent;

UCLASS(Blueprintable, MinimalAPI)
class ACameraStackSplineActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackSplineType SplineType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACameraStackSplineActor* RailPairedSplineActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDifferentSplineWhenStartingAtEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACameraStackSplineActor* RailPairedSplineActorStartingAtEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SplineComponent;
    
    ACameraStackSplineActor();
};

