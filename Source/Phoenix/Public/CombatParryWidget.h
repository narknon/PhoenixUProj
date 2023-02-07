#pragma once
#include "CoreMinimal.h"
#include "CombatParryInfo.h"
#include "PhoenixUserWidget.h"
#include "CombatParryWidget.generated.h"

class UCombatParryButtonCallout;
class UObject;

UCLASS(Blueprintable, EditInlineNew)
class UCombatParryWidget : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCombatParryButtonCallout* CombatParryButtonCallout0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCombatParryButtonCallout* CombatParryButtonCallout1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCombatParryButtonCallout* CombatParryButtonCallout2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCombatParryButtonCallout* CombatParryButtonCalloutForOutro;
    
private:
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCombatParryInfo> CombatParryInfos;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UCombatParryButtonCallout*> CombatParryButtonCallouts;
    
public:
    UCombatParryWidget();
private:
    UFUNCTION(BlueprintCallable)
    void CombatParryInfoTimerFinished(const UObject* Caller, const int32 WindowID, int32 ParryType);
    
};

