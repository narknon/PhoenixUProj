#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "OdcObstacleData.h"
#include "OdcObstacleComponent.generated.h"

class UActorComponent;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ODYSSEYRUNTIME_API UOdcObstacleComponent : public USceneComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcObstacleData ObstacleData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExcludeIfParentHasAuthoredObstacle;
    
public:
    UOdcObstacleComponent();
    UFUNCTION(BlueprintCallable)
    void SetFlag(const FName FlagName);
    
    UFUNCTION(BlueprintCallable)
    void ClearFlag(const FName FlagName);
    
    UFUNCTION(BlueprintCallable)
    void AddComponentObstaclesBP(TArray<UActorComponent*> IncludeComponents, bool RemoveUnknownObstacles);
    
    UFUNCTION(BlueprintCallable)
    void AddActorComponentObstaclesBP(bool RemoveUnknownObstacles, TArray<UActorComponent*> ExcludeComponents);
    
};

