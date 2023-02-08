#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FishMoverBase.generated.h"


class USkeletalMesh;
class USkeletalMeshComponent;
class USplineComponent;

UCLASS(Blueprintable)
class AFishMoverBase : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> FishOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USplineComponent*> Splines;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USkeletalMeshComponent*> FishComponents;
    
public:
    AFishMoverBase();
    UFUNCTION(BlueprintCallable)
    void MoveFish(float timelineTime);
    
    UFUNCTION(BlueprintCallable)
    void InitFish(int32 numberOfFish, USkeletalMesh* Mesh, UAnimationAsset* Anim, float ScaleMin, float ScaleMax, float spacing);
    
    UFUNCTION(BlueprintCallable)
    void AddFishSpline(USplineComponent* Spline);
    
};

