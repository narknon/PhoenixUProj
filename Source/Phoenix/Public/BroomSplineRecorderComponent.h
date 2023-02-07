#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "BroomSplinePlaybackDelegateDelegate.h"
#include "BroomSplineRecorderComponent.generated.h"

class USplineComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBroomSplineRecorderComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBroomSplinePlaybackDelegate BroomSplineRecordDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBroomSplinePlaybackDelegate BroomSplinePlaybackDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBroomSplinePlaybackDelegate BroomSplineStopPlaybackDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SplineToPlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SplineToStop;
    
    UBroomSplineRecorderComponent();
    UFUNCTION(BlueprintCallable)
    void SaveSplineToEditor(const USplineComponent* SplineToSave);
    
    UFUNCTION(BlueprintCallable)
    bool IsRecording();
    
};

