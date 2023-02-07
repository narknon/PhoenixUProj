#pragma once
#include "CoreMinimal.h"
#include "WorldInteractObject.h"
#include "FlyingBook.generated.h"

class USphereComponent;
class USplineComponent;

UCLASS(Blueprintable)
class PHOENIX_API AFlyingBook : public AWorldInteractObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BookSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BookSpeedMod;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USplineComponent* MainSplineReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USphereComponent* BookRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float SplineLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float DistanceAlongSpline;
    
public:
    AFlyingBook();
    UFUNCTION(BlueprintCallable)
    void Update(float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void RandomizeDistanceAlongSpline();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ActivateSpellReaction(bool newActivate);
    
};

