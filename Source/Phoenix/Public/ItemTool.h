#pragma once
#include "CoreMinimal.h"
#include "Tool.h"
#include "ItemTool.generated.h"

class ACharacter;
class UItemToolRecord;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class AItemTool : public ATool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* AbleExecutionClass;
    
    AItemTool(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemToolRecord* GetItemToolRecord() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter* GetCharacter() const;
    
};

