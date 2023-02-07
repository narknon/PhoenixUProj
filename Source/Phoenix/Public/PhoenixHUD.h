#pragma once
#include "CoreMinimal.h"
#include "EStandardManagedPriority.h"
#include "CharacterStateHUD.h"
#include "MailEntry.h"
#include "Templates/SubclassOf.h"
#include "PhoenixHUD.generated.h"

class UCurveFloat;
class UFont;
class UMaterialInterface;
class UObject;
class UPhoenixHUDWidget;
class UReticule;
class UTexture2D;
class UUserWidget;

UCLASS(Blueprintable, NonTransient)
class PHOENIX_API APhoenixHUD : public ACharacterStateHUD {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFont* VerdanaFont;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFont* UE4Font;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultFontScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GlobalHUDMult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* CursorMain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* CursorHoveringButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* ButtonBackground;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* MaterialBackground;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_subReticuleMoveToTargetTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> m_ReticuleWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> LoadingScreenWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixHUDWidget* HUDWidgetRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool KnowledgeNotificationShown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString KnowledgeNotificationSubject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowAnimDebugInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StickX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StickY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ModifiedStickX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ModifiedStickY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* DeadZoneCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* SpeedCurve;
    
    APhoenixHUD();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ToggleHUD(bool Show, bool AllowSelectiveTicking, bool AllowAnimation);
    
public:
    UFUNCTION(BlueprintCallable)
    void StartSettingHUDVisible(bool bNewValue, EStandardManagedPriority Priority, const UObject* Provider, bool AllowAnimation);
    
    UFUNCTION(BlueprintCallable, Exec)
    void ShowHUDGroup(const FString& GroupName, UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    void SetDefaultHUDVisible(bool bDefaultValue, bool AllowSelectiveTicking);
    
    UFUNCTION(BlueprintCallable)
    void ReadActiveOwlMail();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnMailRecieved(FMailEntry Entry, int32 DisplayPriority);
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void HideHUDGroup(const FString& GroupName, UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    void HandleHUDGroupUnregistration(const UObject* i_caller, const FName& HUDGroupName);
    
    UFUNCTION(BlueprintCallable)
    void HandleHUDGroupRegistration(const UObject* i_caller, const FName& HUDGroupName);
    
    UFUNCTION(BlueprintCallable)
    UReticule* GetReticuleWidget();
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingHUDVisible(EStandardManagedPriority Priority, const UObject* Provider, bool AllowAnimation);
    
    UFUNCTION(BlueprintCallable)
    void EnableAnimDebugInfo(bool bInFlag);
    
};

