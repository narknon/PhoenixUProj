#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EnemyInfo.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UEnemyInfo : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Health;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Visible;
    
    UEnemyInfo();
    UFUNCTION(BlueprintCallable)
    void Show(bool VisibleIn);
    
    UFUNCTION(BlueprintCallable)
    void SetName(FName NameIn);
    
    UFUNCTION(BlueprintCallable)
    void SetHelthPercentage(float HealthIn);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleShow(bool VisibleIn);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleNameChanged(FName NameIn);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleHealthPercentageChanged(float HealthIn);
    
};

