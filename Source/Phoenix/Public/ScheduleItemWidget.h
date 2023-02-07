#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActivityStruct.h"
#include "ScheduleItemHoverDelegateDelegate.h"
#include "ScheduleItemUnHoverDelegateDelegate.h"
#include "ScheduleItemWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UScheduleItemWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScheduleItemHoverDelegate OnScheduleItemHovered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScheduleItemUnHoverDelegate OnScheduleItemUnhovered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BackgroundScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString IconName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EndTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ActivityID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ActivityTypeID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowActivityText;
    
    UScheduleItemWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool SetInformation(FActivityStruct Activity, bool ShowText);
    
    UFUNCTION(BlueprintCallable)
    void ScheduleItemUnhovered();
    
    UFUNCTION(BlueprintCallable)
    void ScheduleItemHovered();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
};

