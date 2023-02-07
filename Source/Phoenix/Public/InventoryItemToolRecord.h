#pragma once
#include "CoreMinimal.h"
#include "ToolRecord.h"
#include "InventoryItemToolRecord.generated.h"

class AInventoryItemTool;
class UInventoryItemToolRecord;

UCLASS(Blueprintable)
class UInventoryItemToolRecord : public UToolRecord {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLoadComplete, UInventoryItemToolRecord*, ToolRecord);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AInventoryItemTool> InventoryItemTool;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLoadComplete OnLoadComplete;
    
    UInventoryItemToolRecord();
    UFUNCTION(BlueprintCallable)
    void LoadComplete();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLoaded() const;
    
};

