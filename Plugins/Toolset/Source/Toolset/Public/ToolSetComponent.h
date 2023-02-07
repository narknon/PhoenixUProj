#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EStandardManagedPriority.h"
#include "ToolSetComponent.generated.h"

class ATool;
class UObject;
class USceneComponent;
class UToolRecord;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class TOOLSET_API UToolSetComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActiveToolChanged, ATool*, Activated, ATool*, Deactivated);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UToolRecord*> ToolRecords;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActiveToolChanged OnActiveToolChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UToolRecord*, ATool*> SpawnedToolsMap;
    
public:
    UToolSetComponent();
    UFUNCTION(BlueprintCallable)
    void StartSettingWhitelistedTools(const TArray<UToolRecord*>& InTools, EStandardManagedPriority InPriority, const UObject* InProvider);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingBlacklistedTools(const TArray<UToolRecord*>& InTools, EStandardManagedPriority InPriority, const UObject* InProvider);
    
    UFUNCTION(BlueprintCallable)
    void SetAttachmentParent(USceneComponent* InOwnerMesh);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsToolUsageAllowed(const UToolRecord* ToolRecord) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UToolRecord*> GetToolRecords() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetToolRecordIndex(const UToolRecord* ToolRecord) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UToolRecord* GetToolRecordByName(const FName Name) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USceneComponent* GetAttachmentParent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetActiveToolRecordIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ATool* GetActiveTool() const;
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingWhitelistedTools(EStandardManagedPriority InPriority, const UObject* InProvider);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingBlacklistedTools(EStandardManagedPriority InPriority, const UObject* InProvider);
    
    UFUNCTION(BlueprintCallable)
    ATool* ClearActiveTool();
    
    UFUNCTION(BlueprintCallable)
    void AsyncLoadToolByName(const FName Name);
    
    UFUNCTION(BlueprintCallable)
    ATool* ActivateToolByName(const FName Name);
    
    UFUNCTION(BlueprintCallable)
    ATool* ActivateTool(UToolRecord* ToolRecord);
    
    UFUNCTION(BlueprintCallable)
    ATool* ActivateExistingTool(ATool* Tool);
    
};

