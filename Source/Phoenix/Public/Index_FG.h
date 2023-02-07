#pragma once
#include "CoreMinimal.h"
#include "TabPageWidget.h"
#include "Index_FG.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UIndex_FG : public UTabPageWidget {
    GENERATED_BODY()
public:
    UIndex_FG();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetSchoolPct(float OldPct, float NewPct);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetPlayerLevel(int32 NewLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetActionsPct(float OldPct, float NewPct);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnGetAvailableAssignments(const FString& DisplayText);
    
    UFUNCTION(BlueprintCallable)
    void GetAvailableAssignments();
    
};

