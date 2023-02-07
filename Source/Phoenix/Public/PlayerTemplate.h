#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PlayerTemplate.generated.h"

class UPlayerTemplate;

UCLASS(Blueprintable)
class UPlayerTemplate : public UObject {
    GENERATED_BODY()
public:
    UPlayerTemplate();
    UFUNCTION(BlueprintCallable, Exec)
    void RemovePlayerTemplate();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ReloadPlayerTemplate(FName PlayerTemplateName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void PlayerTemplateLogObjInfo();
    
    UFUNCTION(BlueprintCallable, Exec)
    void PlayerTemplateBuildCSVInfo();
    
    UFUNCTION(BlueprintCallable)
    static UPlayerTemplate* Get();
    
};

