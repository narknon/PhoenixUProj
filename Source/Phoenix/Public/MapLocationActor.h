#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "Engine/StaticMeshActor.h"
#include "MapLocationActor.generated.h"

class UArrowComponent;
class UMapCameraParameters;

UCLASS(Blueprintable)
class AMapLocationActor : public AStaticMeshActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo MyLocationID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapCameraParameters* CameraParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Visited;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsTower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HasMaterialInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RegionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UArrowComponent* TargetFocusPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsHighlighted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsForward;
    
    AMapLocationActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPushBackward_Event();
    
    UFUNCTION(BlueprintCallable)
    void OnPushBackward();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBringForward_Event();
    
    UFUNCTION(BlueprintCallable)
    void OnBringForward();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActivateHighlight_Event(bool Activate);
    
    UFUNCTION(BlueprintCallable)
    void OnActivateHighlight(bool Activate);
    
};

