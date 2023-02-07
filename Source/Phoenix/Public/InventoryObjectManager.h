#pragma once
#include "CoreMinimal.h"
#include "GameplayProperty_Int.h"
#include "Moddable.h"
#include "PhxDbRegistryTypeManager.h"
#include "InventoryObjectManager.generated.h"

class AActor;

UCLASS(Blueprintable)
class UInventoryObjectManager : public UPhxDbRegistryTypeManager, public IModdable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayProperty_Int MaxStackModifier;
    
public:
    UInventoryObjectManager();
    UFUNCTION()
    void SaveData(const FString& InItemID, AActor* TargetActor, uint32 inParentUID, uint32 inOverrideUID);
    
    
    // Fix for true pure virtual functions not being implemented
};

