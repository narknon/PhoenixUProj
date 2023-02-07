#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TargetCallOutWidget.generated.h"

class AActor;
class UCallOutComponent;
class UWidget;

UINTERFACE(Blueprintable)
class UTargetCallOutWidget : public UInterface {
    GENERATED_BODY()
};

class ITargetCallOutWidget : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateCallOutUI(FName CharacterID, float BarPercent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ShowWidget(bool Revealio);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetupWidget(AActor* Parent, UCallOutComponent* CallOutComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetIsOffscreenCallout(bool IsOffscreen);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetHasOffscreenProxyActive(bool HasOffscreenProxy);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetOutroDuration(const int32 OutroType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UWidget* GetOffscreenIndicator();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AwareStateInfoChanged(bool bFromUpdate);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AttackThreatDataChange(bool Revealio);
    
};

