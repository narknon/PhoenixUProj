#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/WidgetComponent.h"
#include "AssociatedBeaconUpdatedDelegate.h"
#include "AttackStateInfo.h"
#include "AwareStateInfo.h"
#include "Enemy_AttackThreatData.h"
#include "CallOutComponent.generated.h"

class UCanvasPanelSlot;
class UEnemyAIComponent;
class UObject;
class UPhoenixUserWidget;
class UScheduledEntity;
class UWidget;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCallOutComponent : public UWidgetComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OnScreen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool targeted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnemytoPlayer;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAssociatedBeaconUpdated OnAssociatedBeaconUpdated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BeaconIconName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BeaconTrackingBorder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor BeaconColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BeaconSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsBeaconTracked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAttackStateInfo CurrentAttackStateInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAwareStateInfo CurrentAwareStateInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostAlertKeepActiveTime;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UEnemyAIComponent* EnemyAIComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UScheduledEntity* MyScheduledEntity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* OffScreenWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* OffScreenArrow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanelSlot* OffscreenWidgetHudSlot;
    
public:
    UCallOutComponent();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateCallOutUI();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ShowWidgetForThisCallout();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnOutroEnded(UPhoenixUserWidget* BaseItem, int32 OutroType);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HideWidgetForThisCallout();
    
    UFUNCTION(BlueprintCallable)
    void AwareStateInfoHandler(const UObject* i_caller, const FAwareStateInfo& AwareStateInfo);
    
    UFUNCTION(BlueprintCallable)
    void AttackThreatDataHandler(const UObject* i_caller, const FEnemy_AttackThreatData& AttackThreatData);
    
};

