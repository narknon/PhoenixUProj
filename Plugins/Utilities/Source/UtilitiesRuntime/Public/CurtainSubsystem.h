#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OnCurtainChangedDelegate.h"
#include "OnCurtainStageDelegate.h"
#include "Templates/SubclassOf.h"
#include "CurtainSubsystem.generated.h"

class UObject;
class UUserWidget;

UCLASS(Blueprintable)
class UTILITIESRUNTIME_API UCurtainSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> CurtainWidgetClass;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCurtainChanged OnCurtainLowered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCurtainChanged OnCurtainRaised;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCurtainChanged OnLienholdersChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCurtainStage OnCurtainStageOptionsChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UUserWidget* CurtainWidget;
    
public:
    UCurtainSubsystem();
    UFUNCTION(BlueprintCallable)
    static void LowerCurtain(const UObject* WhosAsking, FName WhatsYourName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsCurtainDown(const UObject* WhosAsking);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetLienholderNames() const;
    
};

