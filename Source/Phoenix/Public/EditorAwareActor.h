#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EditorAwareActor.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API AEditorAwareActor : public AActor {
    GENERATED_BODY()
public:
    AEditorAwareActor();
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void PreEditorChangeProperty(const FName& PropertyName);
    
public:
    UFUNCTION(BlueprintCallable)
    void PostEditorMove(const bool bFinished);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void PostEditorChangeProperty(const FName& PropertyName);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void EditorTick(const float DeltaSeconds);
    
};

