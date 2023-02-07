#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavigationArrow.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class ANavigationArrow : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PathActivationRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NearFadeDistanceOutterRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NearFadeDistanceInnerRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FarFadeDistanceOutterRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FarFadeDistanceInnerRadius;
    
    ANavigationArrow();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowEvent();
    
    UFUNCTION(BlueprintCallable)
    void Show();
    
    UFUNCTION(BlueprintCallable)
    bool IsListVisible();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideEvent();
    
    UFUNCTION(BlueprintCallable)
    void Hide();
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* GetMaterial();
    
};

