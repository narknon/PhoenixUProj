#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "EAccessibilityAudioCueEventType.h"
#include "UIAccessibilityManager.generated.h"

class AActor;
class UCanvasPanel;
class UDataTable;
class UMaterialInterface;
class UUIAccessibilityAudioCueWidget;

UCLASS(Blueprintable)
class UUIAccessibilityManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* AudioCueDataTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* IconRenderWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* IconRenderWidgetSimpleMaterial;
    
public:
    UUIAccessibilityManager();
    UFUNCTION(BlueprintCallable)
    static void TriggerAccessibilityEventLeave(EAccessibilityAudioCueEventType EventType, AActor* EventActor);
    
    UFUNCTION(BlueprintCallable)
    static void TriggerAccessibilityEventEnter(EAccessibilityAudioCueEventType EventType, AActor* EventActor);
    
    UFUNCTION(BlueprintCallable)
    static void TriggerAccessibilityEventDamage(AActor* EventActor, FVector Location, float Angle, float Damage);
    
    UFUNCTION(BlueprintCallable)
    static void TriggerAccessibilityEvent(EAccessibilityAudioCueEventType EventType, AActor* EventActor);
    
    UFUNCTION(BlueprintCallable)
    void DeactivateAudioCues();
    
    UFUNCTION(BlueprintCallable)
    void ActivateAudioCues(UCanvasPanel* pPanel, UUIAccessibilityAudioCueWidget* pWidget);
    
};

