#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MastermindFileHelper.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class UMastermindFileHelper : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMastermindFileHelper();
    UFUNCTION(BlueprintCallable)
    static bool GetVideoCaptureArtifactPath(const FString& InPath, FString& OutPath);
    
    UFUNCTION(BlueprintCallable)
    static bool GetScreenshotArtifactPath(const FString& InPath, FString& OutPath);
    
    UFUNCTION(BlueprintCallable)
    static bool GetProjectLogArtifactPath(const FString& InPath, FString& OutPath);
    
    UFUNCTION(BlueprintCallable)
    static bool GetProfilingArtifactPath(const FString& InPath, FString& OutPath);
    
    UFUNCTION(BlueprintCallable)
    static bool GetBugItArtifactPath(const FString& InPath, FString& OutPath);
    
    UFUNCTION(BlueprintCallable)
    static bool GetAutomationTransientArtifactPath(const FString& InPath, FString& OutPath);
    
    UFUNCTION(BlueprintCallable)
    static bool GetAutomationLogArtifactPath(const FString& InPath, FString& OutPath);
    
    UFUNCTION(BlueprintCallable)
    static bool GetAutomationArtifactPath(const FString& InPath, FString& OutPath);
    
    UFUNCTION(BlueprintCallable)
    static bool GetArtifactAbsolutePath(const FString& InPath, FString& OutPath);
    
};

