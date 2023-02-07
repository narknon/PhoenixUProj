/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/


#include "MovieSceneAkAudioEventTrackEditor.h"

#include "AkAudioBank.h"
#include "AkAudioBankGenerationHelpers.h"
#include "AkAudioBankGenerationHelpers.h"
#include "AkAudioDevice.h"
#include "AkAudioStyle.h"
#include "AkWaapiClient.h"
#include "AssetRegistryModule.h"
#include "Async/Async.h"
#include "CommonMovieSceneTools.h"
#include "ContentBrowserModule.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "IAssetRegistry.h"
#include "IContentBrowserSingleton.h"
#include "ISequencerSection.h"
#include "MovieScene.h"
#include "MovieSceneAkAudioEventSection.h"
#include "MovieSceneAkAudioEventTrack.h"
#include "MovieSceneCommonHelpers.h"
#include "Rendering/DrawElements.h"
#include "RenderUtils.h"
#include "ScopedTransaction.h"
#include "SequencerSectionPainter.h"
#include "SequencerUtilities.h"
#include "Slate/SlateTextures.h"
#include "Textures/SlateTextureData.h"

#define LOCTEXT_NAMESPACE "MovieSceneAkAudioEventTrackEditor"

/** A viewport that maintains a waveform texture for a Wwise event. */
class AkAudioWaveformViewport
    : public ISlateViewport
{
public:
    /** Represents a waveform texture with a given size that covers a given time range. */
    struct WaveformDescriptor
    {
        WaveformDescriptor()
        {
            TimeRangeInView = TRange<float>(0.0f, 0.0f);
            TextureSize = FVector2D(0.0f, 0.0f);
        }

        WaveformDescriptor(TRange<float> in_TimeRangeInView, FVector2D in_TextureSize)
            : TimeRangeInView(in_TimeRangeInView)
            , TextureSize(in_TextureSize)
        {}

        WaveformDescriptor(const WaveformDescriptor& in_Other)
            : TimeRangeInView(in_Other.TimeRangeInView)
            , TextureSize(in_Other.TextureSize)
        {}

        bool Equals(const WaveformDescriptor& in_Other)
        {
            if (!FMath::IsNearlyEqual(TimeRangeInView.GetLowerBoundValue(), in_Other.TimeRangeInView.GetLowerBoundValue(), 0.01f))
                return false;
            if (!FMath::IsNearlyEqual(TimeRangeInView.GetUpperBoundValue(), in_Other.TimeRangeInView.GetUpperBoundValue(), 0.01f))
                return false;
            if (!FMath::IsNearlyEqual(TextureSize.X, in_Other.TextureSize.X, 0.01f) || !FMath::IsNearlyEqual(TextureSize.Y, in_Other.TextureSize.Y, 0.01f))
                return false;
            return true;
        }

        /** The range of time within the AK audio event section that can be seen within the view. */
        TRange<float> TimeRangeInView;
        /** The size of the waveform texture. */
        FVector2D     TextureSize;
    };

    /** AkAudioWaveformViewport Constructor. */
    AkAudioWaveformViewport(UMovieSceneAkAudioEventSection& InSection, AkAudioWaveformViewport::WaveformDescriptor in_Descriptor, 
                            int in_iNumPeaksRequired, int in_iLeftOverPixels, FTimeToPixel in_TimeToPixelConverter, 
                            TArray<double> in_aPeakDataCache, float InDisplayScale = 1.0f);

    ~AkAudioWaveformViewport()
    {
        if (ShouldRender())
        {
            BeginReleaseResource(Texture);
            FlushRenderingCommands();
        }

        if (Texture)
        {
            delete Texture;
        }
    }


    /** The AK audio event section in the UE sequencer */
    UMovieSceneAkAudioEventSection& Section;

    /** The waveform texture is created with a cache of the latest peak data for the Wwise event. */
    TArray<double>PeakDataCache;

    /** The waveform texture */
    class FSlateTexture2DRHIRef* Texture;
    
    /** Represents a waveform texture with a given size that covers a given time range. */
    WaveformDescriptor Descriptor;

    /** The number of peaks required depends on the zoom level, the section length, and whether the section is clipped. 
     *  If the section is clipped, we ask for some extra peaks beyond the clipped region (see FMovieSceneAkAudioEventSection::UpdatePeaks)
     */
    int NumPeaksRequired = 0;
    /** Pixels left over between end of smoothed waveform and end of waveform duration. */
    int LeftOverPixels = 0;

    /** Used to convert pixels to time (seconds) */
    FTimeToPixel  TimeToPixelConverter;

    bool ShouldRender() const { return Descriptor.TextureSize.X > 0; }

    /** NumChannels should come from WAAPI data. */
    int NumChannels = 1;

    /** Amount by which waveform peaks are smoothed (SmoothingAmount pixels per peak) */
    static const int SmoothingAmount = 5;

    float DisplayScale = 1.0f;

    /* ISlateViewport interface */
    virtual FIntPoint GetSize() const override 
    { 
        return FIntPoint((int)Descriptor.TextureSize.X, (int)Descriptor.TextureSize.Y); 
    }
    virtual class FSlateShaderResource* GetViewportRenderTargetTexture() const override;
    virtual bool                        RequiresVsync()                  const override { return false; }
    virtual bool                        AllowScaling()                   const override { return false; }

private:
    /** Generates the waveform texture data. The texture is generated as subsequent vertical pixel strips.
     *  Strips are first initialized (InitializeStrip()), then waveform peak data is used to generate waveform color 
     *  (GenerateWaveformStrip()). Indicator lines are then generated which indicate whether or not the event is 
     *  retriggered after it ends (GenerateIndicatorLine()).
     *
     *  @param OutData - the texture data buffer to fill.
     */
    void GenerateTextureData (TArray<uint8>& OutData);

    /** Gets the interpolated min & max pair values between in_PeakIndex and the next peak index, according to pixel value in_XPosition.
     *  Num pixels per min & max pair in the audio peaks is controlled by SmoothingAmount. 
     */
    FVector2D GetInterpolatedMinMaxPeaks(int in_XPosition, int in_PeakIndex);

    /** Initializes a vertical strip in the texture data to 0. */
    void InitializeStrip(int32 X, int32 ChannelIndex, TArray<uint8>& OutData);
    /** Generates a white vertical strip in the texture. The bottom and top of the strip are determined by in_MinPeakValue and in_MaxPeakValue. */
    void GeneratePeakStrip(int32 X, int32 ChannelIndex, TArray<uint8>& OutData, float in_MinPeakValue, float in_MaxPeakValue);
    /** Generates a white vertical strip in the texture according to the X position. Returns true if X is within the waveform, false otherwise. */
    bool GenerateWaveformStrip(int32 X, int32 ChannelIndex, TArray<uint8>& OutData);
	/** Generates indicators for silence or retriggering in the event sectinon. For silence, a horizontal line is generated. For retriggering, diagonal lines are generated. */
    void GenerateIndicatorLine(int32 X, int32 ChannelIndex, TArray<uint8>& OutData);

    /** Fills a pixel with white (if in_bDirty is false) or red (if in_bDirty is true) color. */
    void FillPixel (uint8* Pixel, bool in_bDirty, uint8 A = 255);
    /** Sets a pixel's color and opacity to 0. */
	void EmptyPixel (uint8* Pixel); 
};

class FSlateShaderResource* AkAudioWaveformViewport::GetViewportRenderTargetTexture() const { return Texture; }

/** Lookup a pixel in the given data buffer based on the specified X and Y */
uint8* LookupPixel(TArray<uint8>& Data, int32 X, int32 YPos, int32 Width, int32 Height, int32 Channel, int32 NumChannels)
{
    int32 Y = Height - YPos - 1;
    if (NumChannels == 2)
    {
        Y = Channel == 0 ? Height / 2 - YPos : Height / 2 + YPos;
    }

    int32 Index = (Y * Width + X) * GPixelFormats[PF_B8G8R8A8].BlockBytes;
    if (Index + 3 < Data.Num())
        return &Data[Index];
    UE_LOG(LogTemp, Warning, TEXT("Array overrun in MovieSceneAkAudioEventTrackEditor!"));
    return 0;
}

AkAudioWaveformViewport::AkAudioWaveformViewport(UMovieSceneAkAudioEventSection& InSection, AkAudioWaveformViewport::WaveformDescriptor in_Descriptor, 
                                                 int in_iNumPeaksRequired, int in_iLeftOverPixels, FTimeToPixel in_TimeToPixelConverter, 
                                                 TArray<double> in_aPeakDataCache, float InDisplayScale /* = 1.0f */)
    : Section(InSection)
    , PeakDataCache(in_aPeakDataCache)
    , Texture(NULL)
    , Descriptor(in_Descriptor)
    , NumPeaksRequired(in_iNumPeaksRequired)
    , LeftOverPixels(in_iLeftOverPixels)
    , TimeToPixelConverter(in_TimeToPixelConverter)
    , DisplayScale(InDisplayScale)
{
    if (ShouldRender())
    {
        uint32 Size = GetSize().X * GetSize().Y * GPixelFormats[PF_B8G8R8A8].BlockBytes;
        TArray<uint8> RawData;
        RawData.AddZeroed(Size);
        
        GenerateTextureData(RawData);

        FSlateTextureDataPtr BulkData(new FSlateTextureData(GetSize().X, GetSize().Y, GPixelFormats[PF_B8G8R8A8].BlockBytes, RawData));

        Texture = new FSlateTexture2DRHIRef(GetSize().X, GetSize().Y, PF_B8G8R8A8, BulkData, TexCreate_Dynamic);

        BeginInitResource(Texture);
    }
}

void AkAudioWaveformViewport::EmptyPixel(uint8* Pixel)
{
	*Pixel       = (uint8)0;
	*(Pixel + 1) = (uint8)0;
	*(Pixel + 2) = (uint8)0;
	*(Pixel + 3) = (uint8)0;
}

void AkAudioWaveformViewport::FillPixel(uint8* Pixel, bool in_bDirty, uint8 A /*= 255*/)
{
    float AlphaPreMultiply = (float)A / 255.0f;
	*Pixel       = (uint8)((in_bDirty ? 50 : 130) * AlphaPreMultiply);  //B
	*(Pixel + 1) = (uint8)((in_bDirty ? 50 : 130) * AlphaPreMultiply);  //G
	*(Pixel + 2) = (uint8)((in_bDirty ? 130 : 130) * AlphaPreMultiply); //R
	*(Pixel + 3) = A;
}

/** Initializes a vertical strip in the texture data to 0. */
void AkAudioWaveformViewport::InitializeStrip(int32 X, int32 ChannelIndex, TArray<uint8>& OutData)
{
    int32 Width        = (int32)GetSize().X;
    int32 Height       = (int32)GetSize().Y;
    int32 MaxAmplitude = (int32)(Height * DisplayScale);
    for (int32 PixelIndex = 0; PixelIndex < MaxAmplitude; ++PixelIndex)
    {
        uint8* Pixel = LookupPixel(OutData, X, PixelIndex, Width, Height, ChannelIndex, NumChannels);
        EmptyPixel(Pixel);
    }
}

/** Generates a white vertical strip in the texture. The bottom and top of the strip are determined by in_MinPeakValue and in_MaxPeakValue. */
void AkAudioWaveformViewport::GeneratePeakStrip(int32 X, int32 ChannelIndex, TArray<uint8>& OutData, float in_MinPeakValue, float in_MaxPeakValue)
{
    const int   Height = GetSize().Y;
    const int   ZeroLine = Height / 2;
    const float AbsMaxAmp = Height * DisplayScale * 0.5f;
    const int32 MinPixelIndex = ZeroLine + (int32)(in_MinPeakValue * AbsMaxAmp);
    const int32 MaxPixelIndex = ZeroLine + (int32)(in_MaxPeakValue * AbsMaxAmp);
    for (int32 PixelIndex = 0; PixelIndex < Height; ++PixelIndex)
    {
        uint8* Pixel = LookupPixel(OutData, X, PixelIndex, GetSize().X, Height, ChannelIndex, NumChannels);
        if (PixelIndex >= MinPixelIndex && PixelIndex <= MaxPixelIndex)
        {
            FillPixel(Pixel, Section.EventTracker->IsDirty);
        }
    }
}

/** Gets the interpolated min & max pair values between in_PeakIndex and the next peak index, according to pixel value in_XPosition.
 *  Num pixels per min & max pair in the audio peaks is controlled by SmoothingAmount.
 */
FVector2D AkAudioWaveformViewport::GetInterpolatedMinMaxPeaks(int in_XPosition, int in_PeakIndex)
{
    const int NumPeaks = PeakDataCache.Num() / 2;

    const float CurrentMinPeak = (float)PeakDataCache[in_PeakIndex * 2];
    const float CurrentMaxPeak = (float)PeakDataCache[in_PeakIndex * 2 + 1];
    float MinPeakValue = CurrentMinPeak;
    float MaxPeakValue = CurrentMaxPeak;
    if (in_PeakIndex < NumPeaks - 1)
    {
        const float NextMinPeak = (float)PeakDataCache[(in_PeakIndex + 1) * 2];
        const float NextMaxPeak = (float)PeakDataCache[(in_PeakIndex + 1) * 2 + 1];
        const float ModX = FMath::Fmod((float)in_XPosition, SmoothingAmount);
        const float SmoothedSlope = FMath::SmoothStep(0.0f, 1.0f, ModX / (float)SmoothingAmount);
        MinPeakValue = CurrentMinPeak + (NextMinPeak - CurrentMinPeak) * SmoothedSlope;
        MaxPeakValue = CurrentMaxPeak + (NextMaxPeak - CurrentMaxPeak) * SmoothedSlope;
    }
    return FVector2D(MinPeakValue, MaxPeakValue);
}

/** Generates indicators for silence or retriggering in the event sectinon. For silence, a horizontal line is generated. For retriggering, diagonal lines are generated. */
void AkAudioWaveformViewport::GenerateIndicatorLine(int32 X, int32 ChannelIndex, TArray<uint8>& OutData)
{
    auto iSizeY = GetSize().Y;
    int32 iLineY = Section.DoesEventRetrigger() ? FMath::Fmod((float)X, (float)iSizeY) : iSizeY / 2;
    int32 iLineHeight = Section.DoesEventRetrigger() ? 2 : 1;
    for (int32 i = 0; i < iLineHeight; ++i)
    {
        int32 Y = iLineY - i;
        if (Y >= 0 && Y < GetSize().Y && X > 0 && X < GetSize().X)
        {
            uint8* Pixel = LookupPixel(OutData, X, Y, GetSize().X, iSizeY, ChannelIndex, NumChannels);
            FillPixel(Pixel, false);
        }
    }
}

/** Generates a white vertical strip in the texture according to the X position. */
bool AkAudioWaveformViewport::GenerateWaveformStrip(int32 X, int32 ChannelIndex, TArray<uint8>& OutData)
{
    const int NumPeaks  = PeakDataCache.Num() / 2;
    if (NumPeaks > 0)
    {
        const int NumPixelsPerPeak = ((NumPeaksRequired - NumPeaks) / NumPeaks) + 1;
        const int PeakIndex = (X / NumPixelsPerPeak) / SmoothingAmount;
        if (PeakIndex < NumPeaks)
        {
            FVector2D MinMaxPeaks = GetInterpolatedMinMaxPeaks(X, PeakIndex);
            GeneratePeakStrip(X, ChannelIndex, OutData, MinMaxPeaks.X, MinMaxPeaks.Y);
            return true;
        }
    }
    return false;
}

/** Generates the waveform texture data. The texture is generated as subsequent vertical pixel strips.
 *  Strips are first initialized (InitializeStrip()), then waveform peak data is used to generate waveform color
 *  (GenerateWaveformStrip()), then vertical delimitars are drawn at the beginnings and ends of event retriggers
 *  (CheckEventEndStart()).
 *
 *  @param OutData - the texture data buffer to fill.
 */
void AkAudioWaveformViewport::GenerateTextureData(TArray<uint8>& OutData)
{
    //Draw the longest waveform in the event, then leave a space for the event duration, then indicate retrigger or silence.
    int32 iXPosition = 0;
    if (NumPeaksRequired > 0)
    {
        bool bDrawingWaveform = true;
        while (iXPosition < GetSize().X && bDrawingWaveform)
        {
            for (int32 ChannelIndex = 0; ChannelIndex < NumChannels; ++ChannelIndex)
            {
                InitializeStrip(iXPosition, ChannelIndex, OutData);
                bDrawingWaveform = GenerateWaveformStrip(iXPosition, ChannelIndex, OutData);
                if (!bDrawingWaveform)
                    break;
            }
            if (bDrawingWaveform)
                ++iXPosition;
        }
        /* In the case where we have some pixels left over at the end of the smoothed waveform, we fill the zero line. */
        const int32 SourceEnd = iXPosition + LeftOverPixels;
        for (int32 iLeftOver = iXPosition; iLeftOver < SourceEnd; ++iLeftOver)
        {
            if (iLeftOver >= GetSize().X)
                break;
            for (int32 ChannelIndex = 0; ChannelIndex < NumChannels; ++ChannelIndex)
            {
                uint8* Pixel = LookupPixel(OutData, iLeftOver, GetSize().Y / 2, GetSize().X, GetSize().Y, ChannelIndex, NumChannels);
                FillPixel(Pixel, Section.EventTracker->IsDirty);
            }
        }
    }
    /* Generate indicator lines (flat horizontal line for silence, repeating diagonal lines for retrigger). This starts after the duration of the Wwise event. */
	const int EventDurationEndPixel = AkMax(0, TimeToPixelConverter.SecondsToPixel(Section.GetStartTime() + Section.GetEventDuration().GetUpperBoundValue()));
	const int ClippedEventDurationEndPixel = AkMax(0, EventDurationEndPixel - TimeToPixelConverter.SecondsToPixel(Descriptor.TimeRangeInView.GetLowerBoundValue()));
    if (ClippedEventDurationEndPixel >= 0 && ClippedEventDurationEndPixel < GetSize().X && iXPosition < GetSize().X)
    {
        for (int32 X = ClippedEventDurationEndPixel; X < GetSize().X; ++X)
        {
            for (int32 ChannelIndex = 0; ChannelIndex < NumChannels; ++ChannelIndex)
            {
                GenerateIndicatorLine(X, ChannelIndex, OutData);
            }
        }
    }
}

/**
 * Class that draws a transform section in the sequencer.
 * This class maintains an AkAudioWaveformViewport and various properties about the AK audio event section within the UE sequencer.
 * When any of these properties change, the AkAudioWaveformViewport is regenerated.
 */
class FMovieSceneAkAudioEventSection
	: public ISequencerSection
{
public:

	FMovieSceneAkAudioEventSection(UMovieSceneSection& InSection, TWeakPtr<ISequencer> InSequencer)
		: Section(Cast<UMovieSceneAkAudioEventSection>(&InSection))
        , Sequencer(InSequencer)
	{
        PeakDataCache.Empty();

		if (FAkWaapiClient::Get())
		{
			/* Waveform upates depend on WAAPI connection and which project is loaded. */
			ShouldUpdateWaveform = WaapiReconnected = FAkWaapiClient::IsProjectLoaded();
			/* When the correct project is loaded (and we get the project loaded callback) we resume waveform updates. */
			ProjectLoadedHandle = FAkWaapiClient::Get()->OnProjectLoaded.AddLambda([this]
			{
				ResumeWaveformUpdates();
			});
			/* Stop waveform updates when connection is lost (this is also called when a different project is loaded). */
			ConnectionLostHandle = FAkWaapiClient::Get()->OnConnectionLost.AddLambda([this]
			{
				StopWaveformUpdates();
			});
		}

        /* When soundbanks are loaded, we check for workunit changes and set the relevant sections as dirty. */
		if (FAkAudioDevice::Get())
		{
			SoundbanksLoadedHandle = FAkAudioDevice::Get()->OnSoundbanksLoaded.AddLambda([this]
			{
				if (Section != nullptr && Section->EventTracker.IsValid())
				{
					Section->CheckForWorkunitChanges();
				}
			});
		}
    }

    ~FMovieSceneAkAudioEventSection()
    {
        auto pAudioDevice = FAkAudioDevice::Get();
        if (pAudioDevice != nullptr)
            WwiseEventTriggering::StopAllPlayingIDs(pAudioDevice, *Section->EventTracker);

        if (ProjectLoadedHandle.IsValid())
        {
            FAkWaapiClient::Get()->OnProjectLoaded.Remove(ProjectLoadedHandle);
            ProjectLoadedHandle.Reset();
        }
        if (ConnectionLostHandle.IsValid())
        {
            FAkWaapiClient::Get()->OnConnectionLost.Remove(ConnectionLostHandle);
            ConnectionLostHandle.Reset();
        }
        if (SoundbanksLoadedHandle.IsValid())
        {
            FAkAudioDevice::Get()->OnSoundbanksLoaded.Remove(SoundbanksLoadedHandle);
            SoundbanksLoadedHandle.Reset();
        }

        // Wait for any get peak tasks to finish.
        FScopeLock Lock(&FetchPeaksSection);
        while (PeakDataUpdating) {}
    }
public:

	// ISequencerSection interface

	virtual UMovieSceneSection* GetSectionObject() override { return Section; }

	virtual FText GetSectionTitle() const override
	{
        if (Section != nullptr)
        {
            FString name = Section->GetEventName();
			if (name.IsEmpty())
			{
				name = TEXT("(None)");
			}
			if (Section->EventTracker->IsDirty)
			{
				name += "*";
			}
            return FText::FromString(name);
        }
		return FText::GetEmpty();
	}

	virtual int32 OnPaintSection(FSequencerSectionPainter& InPainter) const override
	{
        int32 LayerId = InPainter.PaintSectionBackground();
        
        if (WaveformViewport.IsValid() && WaveformViewport->ShouldRender())
        {
            FSlateLayoutTransform t = FSlateLayoutTransform(1.0f, FVector2D(PixelOffsetLeft, 0.0f));
            
            FSlateDrawElement::MakeViewport(
                InPainter.DrawElements,
                LayerId++,
                InPainter.SectionGeometry.ToPaintGeometry(t),
                WaveformViewport,
                (InPainter.bParentEnabled ? ESlateDrawEffect::None : ESlateDrawEffect::DisabledEffect) | ESlateDrawEffect::NoGamma,
                FLinearColor::White
            );
        }

        return LayerId;
	}

    /**
    * Builds up the section context menu for the outliner
    *
    * @param MenuBuilder	The menu builder to change
    * @param ObjectBinding The object guid bound to this section
    */
    virtual void BuildSectionContextMenu(FMenuBuilder& MenuBuilder, const FGuid& ObjectBinding) override
    {
        MenuBuilder.BeginSection("Audiokinetic", LOCTEXT("AKMenu", "Audiokinetic"));
        {
            MenuBuilder.AddMenuEntry(
                LOCTEXT("WaveformRefresh", "Save Wwise project and refresh."),
                LOCTEXT("WaveformRefreshTooltip", "Saves the Wwise project, generates the required soundbank, and refreshes the waveform to match changes in Wwise."),
                FSlateIcon(),
                FUIAction(
                    FExecuteAction::CreateLambda([=] { return CreateGenerateRequiredSoundbankWindow(); }),
                    FCanExecuteAction::CreateLambda([=] 
                    { 
                        return !(Section == nullptr || !Section->IsValidLowLevelFast() || Section->GetEvent() == nullptr);
                    })
                ), 
                NAME_None,
                EUserInterfaceActionType::Button
            );

            MenuBuilder.AddMenuEntry(
                LOCTEXT("SnapLength", "Match section length to Wwise event length"),
                LOCTEXT("SnapLengthTooltip", "Set the section length to equal the maximum possible duration of the Wwise event."),
                FSlateIcon(),
                FUIAction(
                    FExecuteAction::CreateLambda([=] { return SnapSectionLengthToEventLength(); }),
                    FCanExecuteAction::CreateLambda([=] { return Section != nullptr; })
                ),
                NAME_None,
                EUserInterfaceActionType::Button
            );
        }
        MenuBuilder.EndSection();//Audiokinetic
    }

private:
    /* Callback handles. */
    FDelegateHandle ProjectLoadedHandle;
    FDelegateHandle ConnectionLostHandle;
    FDelegateHandle SoundbanksLoadedHandle;

	/** The section we are visualizing */
	UMovieSceneAkAudioEventSection* Section;
    /** The peak data that we use to construct the waveform texture. 
     *  This comes from the Section's peak data, and is copied during the UpdatePeaks function.
     */
    TArray<double> PeakDataCache;

    /** The waveform viewport render object. */
    TSharedPtr<class AkAudioWaveformViewport> WaveformViewport;

    /* Stored data to determine when the waveform is invalidated. */
    AkAudioWaveformViewport::WaveformDescriptor StoredWaveformDescriptor;
    float         StoredPixelsPerSecond      = 0.0f;
    bool          StoredEventRetriggers      = false;
    float         StoredPixelWidth           = 0.0f;
    float         StoredStartTime            = 0.0f;
    bool          StoredSectionIsDirty       = false;
    FString       StoredEventName            = "";

    /** Indicates where the audio data should be requested and the waveform re-created on tick when new data is available. 
     *  Should be false when there is no connection to WAAPI.
     */
    bool ShouldUpdateWaveform = false;

    /** This flag is used to update the peaks data and the texture when the WAAPI connection is re-established (or started).
     */
    bool WaapiReconnected = false;

    FCriticalSection FetchPeaksSection;
    FThreadSafeBool PeakDataUpdating = false;
	FThreadSafeBool WaveformNeedsUpdate = false;

    /** The amount of pixels to offset the waveform texture by (if any part of it is clipped beyond the left of the editor view). */
    float PixelOffsetLeft = 0.0f;
    /** The number of pixels "left over" at the end of the smoothed waveform. This will be between 0 and AkAudioWaveformViewport::SmoothingAmount. */
    int LeftOverPixels = 0;
    /** This depends on the zoom level, as well as the position and length of the section*/
    int NumPeaksRequired = 0;

    TWeakPtr<ISequencer> Sequencer;

    /** Sets the length of the section to equal the duration of the Wwise event. */
    void SnapSectionLengthToEventLength()
    {
        if (Section != nullptr)
        {
            Section->MatchSectionLengthToEventLength();
        }
    }

    /** Creates a soundbank generation window with the required soundbank selected. */
    void CreateGenerateRequiredSoundbankWindow()
    {
		if (Section != nullptr)
		{
			const auto SectionEvent = Section->GetEvent();
			if (SectionEvent != nullptr)
			{
				TWeakObjectPtr<UAkAudioBank> pRequiredBank(SectionEvent->RequiredBank);
				TArray<TWeakObjectPtr<UAkAudioBank>> aSoundBanks;
				aSoundBanks.Add(pRequiredBank);
				AkAudioBankGenerationHelper::CreateGenerateSoundDataWindow(&aSoundBanks, true);
			}
		}
    }

    /** Creates the waveform viewport according to the waveform descriptor and the TimeToPixelConverter. */
    void CreateWaveformViewport(FTimeToPixel in_TimeToPixelConverter, AkAudioWaveformViewport::WaveformDescriptor in_Descriptor)
    {
        if (in_Descriptor.TimeRangeInView.IsDegenerate() || in_Descriptor.TimeRangeInView.IsEmpty())
            WaveformViewport.Reset();
        else
        {
            WaveformViewport = MakeShareable(new AkAudioWaveformViewport(*Section, in_Descriptor, NumPeaksRequired, LeftOverPixels, in_TimeToPixelConverter, PeakDataCache));
            WaveformNeedsUpdate = false;
        }
    }

    /** Regenerates the waveform viewport and updates stored data about the waveform, section and event. */
    void RegenerateWaveform(FTimeToPixel in_TimeToPixelConverter, AkAudioWaveformViewport::WaveformDescriptor in_Descriptor)
    {
        CreateWaveformViewport(in_TimeToPixelConverter, in_Descriptor);

        StoredWaveformDescriptor = AkAudioWaveformViewport::WaveformDescriptor(in_Descriptor);
        StoredEventRetriggers = Section->DoesEventRetrigger();

        if (Section->EventTracker.IsValid())
        {
            StoredSectionIsDirty = Section->EventTracker->IsDirty;
        }
    }

    /** Calculates the required number of peaks according to the section's position and length, and the zoom level (captured in in_TimeToPixelConverter).
     *  In a background thread, the section updates its peak data and it is then copied to the peak data cache that is used to generate the waveform viewport.
     */
    void UpdatePeaks(AkAudioWaveformViewport::WaveformDescriptor in_Descriptor, FTimeToPixel in_TimeToPixelConverter)
    {
        const float dTrimmedSourceDuration = Section->GetMaxSourceDuration();
        const double dSectionStart  = (double)Section->GetStartTime();
        /* Get the timeFrom and timeTo of the portion of the source that is in view, relative to the sequencer timeline. */
        double dSequencerTimeFrom = AkMin((double)in_Descriptor.TimeRangeInView.GetLowerBoundValue(), dSectionStart + (double)dTrimmedSourceDuration);
        double dSequencerTimeTo   = AkMin(dSectionStart + (double)dTrimmedSourceDuration, (double)in_Descriptor.TimeRangeInView.GetUpperBoundValue());
        /* Convert to Pixels. */
		const int NumPixelsInWaveform = in_TimeToPixelConverter.SecondsToPixel((float)dSequencerTimeTo) - in_TimeToPixelConverter.SecondsToPixel((float)dSequencerTimeFrom);
        /* Get the timeFrom and timeTo values relative to the source (subtract section start time and add trim begin). */
        const double dTrimmedSourceTimeFrom = dSequencerTimeFrom - dSectionStart + Section->GetTrimBegin();
        double dTrimmedSourceTimeTo = dSequencerTimeTo - dSectionStart + Section->GetTrimBegin();

        /* The extra peak data is for the final pixels, to ensure there is not an empty space of 
         * (PixelsInWaveform - (NumPeaks * (PixelsInWaveform / SmoothingAmount))) 
         * pixels at the end of the section. 
         */
        const int numExtraPeaks = 2;
        NumPeaksRequired = (NumPixelsInWaveform / AkAudioWaveformViewport::SmoothingAmount) + numExtraPeaks;
        LeftOverPixels = AkMax(NumPixelsInWaveform - NumPeaksRequired * AkAudioWaveformViewport::SmoothingAmount, 0);
        if (NumPeaksRequired > 0 && (float)dTrimmedSourceTimeFrom < (float)dTrimmedSourceTimeTo)
        {
            PeakDataUpdating = true;
            AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this, dTrimmedSourceTimeFrom, dTrimmedSourceTimeTo, in_Descriptor]()
            {
                FScopeLock Lock(&FetchPeaksSection);
                Section->UpdateAudioSourcePeaks(NumPeaksRequired, dTrimmedSourceTimeFrom, dTrimmedSourceTimeTo);
                Section->RequiresUpdate = false;
                auto newPeakData = Section->GetAudioSourcePeaks();
                PeakDataCache.Empty();
                PeakDataCache.SetNum(newPeakData.Num());
                memcpy(PeakDataCache.GetData(), newPeakData.GetData(), sizeof(double) * newPeakData.Num());
                WaveformNeedsUpdate = true;
                PeakDataUpdating = false;
            });
        }
    }

	FTimeToPixel CreateTimeToPixelConverter(const FGeometry& AllottedGeometry, float& out_PixelsPerSecond)
	{
		TRange<double> ViewRange(Section->GetStartTime(), Section->GetEndTime());
		double VisibleWidth = FMath::Min(1.0, ViewRange.Size<double>());
		out_PixelsPerSecond = AllottedGeometry.GetLocalSize().X / VisibleWidth;

		FFrameRate   TickResolution = Section->GetTypedOuter<UMovieScene>()->GetTickResolution();
		FTimeToPixel TimeToPixelConverter(AllottedGeometry, ViewRange, TickResolution);
		return TimeToPixelConverter;
	}

    /** Each tick we check whether any of the stored data about the section, event, or waveform has changed such that we need to update */
    void Tick(const FGeometry& AllottedGeometry, const FGeometry& ParentGeometry, const double InCurrentTime, const float InDeltaTime) override
    {
        UMovieSceneTrack* Track = Section->GetTypedOuter<UMovieSceneAkAudioEventTrack>();

        if (Track && ShouldUpdateWaveform)
        {                
            if (Section->InitState == AkEventSectionState::EInitialized)
            {
                if (StoredEventName == "")
                {
                    StoredEventName = Section->GetEventName();
                }
                else if (StoredEventName != Section->GetEventName())
                {
                    /** In the case where the event target for a section is changed, we need to ensure UpdateAudioSourceInfo is called before UpdateAudioSourcePeaks,
                    *  otherwise we'll try to call update peaks with invalid audio source info.
                    */
                    Section->UpdateAudioSourceInfo();
                    StoredEventName = Section->GetEventName();
                }

                if (Section->AudioSourceInfoIsValid())
                {
                    /** Pass on the new ScrubTailLength to the underlying section, if it has been changed via the Editor UI. */
                    if (Section->EventTracker->ScrubTailLengthMs != Section->GetScrubTailLength())
                        Section->EventTracker->ScrubTailLengthMs = Section->GetScrubTailLength();

                    auto Concatenated = Concatenate(ParentGeometry.GetAccumulatedLayoutTransform(), AllottedGeometry.GetAccumulatedLayoutTransform().Inverse());
                    const FSlateRect ParentRect = TransformRect(Concatenated, FSlateRect(FVector2D(0, 0), ParentGeometry.GetLocalSize()));

                    const float LeftMostVisiblePixel = FMath::Max(ParentRect.Left, 0.f);
                    const float RightMostVisiblePixel = FMath::Min(ParentRect.Right, AllottedGeometry.GetLocalSize().X);

                    /** If the section is in view ... */
                    if (RightMostVisiblePixel > LeftMostVisiblePixel)
                    {
						float PixelsPerSecond;
                        FTimeToPixel TimeToPixelConverter = CreateTimeToPixelConverter(AllottedGeometry, PixelsPerSecond);
						TRange<float> TimeRangeInView = TRange<float>(TimeToPixelConverter.PixelToSeconds(LeftMostVisiblePixel),
							TimeToPixelConverter.PixelToSeconds(RightMostVisiblePixel));

                        PixelOffsetLeft = LeftMostVisiblePixel;

                        FVector2D TextureSize((float)(RightMostVisiblePixel - LeftMostVisiblePixel), (float)AllottedGeometry.GetLocalSize().Y);

                        AkAudioWaveformViewport::WaveformDescriptor Descriptor(TimeRangeInView, TextureSize);

                        /** Check if the peak range has changed.
                         *  This occurs when the texture size changes, or when the section is
                         *  clipped beyond the left of the sequencer view (i.e. it's start time is out of view)
                         *  and it has been dragged.
                         */
                        const bool peakRangeChanged = (StoredPixelWidth != TextureSize.X) || (ParentRect.Left > 0.0f && StoredStartTime != Section->GetStartTime());

                        if (StoredPixelsPerSecond != PixelsPerSecond || Section->RequiresUpdate || WaapiReconnected || peakRangeChanged)
                        {
                            StoredPixelWidth = TextureSize.X;
                            StoredStartTime = Section->GetStartTime();
                            /** Update the peak data if it is not currently being updated, and if the duration in view is sufficiently large. */
                            const float minimumDuration = 0.01f;
                            const float durationInView = TimeRangeInView.GetUpperBoundValue() - TimeRangeInView.GetLowerBoundValue();
							if (!PeakDataUpdating && durationInView > minimumDuration && Descriptor.TextureSize.Y > 0.0f)
							{
								UpdatePeaks(Descriptor, TimeToPixelConverter);
								StoredPixelsPerSecond = PixelsPerSecond;
							}
                            if (WaapiReconnected)
                                WaapiReconnected = false;
                        }

                        bool WaveformUpdateRequired = WaveformNeedsUpdate ||
                            ((!StoredWaveformDescriptor.Equals(Descriptor)) && Descriptor.TextureSize.Y > 0.0f) ||
                            StoredEventRetriggers != Section->DoesEventRetrigger();
                        if (Section->EventTracker.IsValid())
                        {
                            WaveformUpdateRequired |= StoredSectionIsDirty != Section->EventTracker->IsDirty;
                        }
                        if (WaveformUpdateRequired)
                        {
                            if (!PeakDataUpdating)
                                RegenerateWaveform(TimeToPixelConverter, Descriptor);
                        }
                    }
                }
                else
                {
                    if (PeakDataCache.Num() > 0)
                    {
                        FScopeLock Lock(&FetchPeaksSection);
                        PeakDataCache.Empty();
                        StoredWaveformDescriptor = AkAudioWaveformViewport::WaveformDescriptor();
						FTimeToPixel TempTimeToPixel(FGeometry(), TRange<double>(0.0f, 0.0f), FFrameRate());
                        RegenerateWaveform(TempTimeToPixel, StoredWaveformDescriptor);
                    }
                }
            }
            else
            {
                Section->Initialize();
            }
        }
        else
        {
            WaveformViewport.Reset();
            StoredWaveformDescriptor = AkAudioWaveformViewport::WaveformDescriptor();
        }
    }

    void ResumeWaveformUpdates()
    {
        Section->UpdateAudioSourceInfo();
        StoredEventName = Section->GetEventName();
        WaapiReconnected = true;
        ShouldUpdateWaveform = true;
    }

    void StopWaveformUpdates()
    {
        ShouldUpdateWaveform = false;
        Section->InvalidateAudioSourceInfo();
    }
};


FMovieSceneAkAudioEventTrackEditor::FMovieSceneAkAudioEventTrackEditor(TSharedRef<ISequencer> InSequencer)
	: FMovieSceneTrackEditor(InSequencer)
{
}

TSharedRef<ISequencerTrackEditor> FMovieSceneAkAudioEventTrackEditor::CreateTrackEditor(TSharedRef<ISequencer> InSequencer)
{
	return MakeShareable(new FMovieSceneAkAudioEventTrackEditor(InSequencer));
}

bool FMovieSceneAkAudioEventTrackEditor::SupportsType(TSubclassOf<UMovieSceneTrack> Type) const
{
    return Type == UMovieSceneAkAudioEventTrack::StaticClass();
}

bool FMovieSceneAkAudioEventTrackEditor::SupportsSequence(UMovieSceneSequence* InSequence) const
{
	static UClass* LevelSequenceClass = FindObject<UClass>(ANY_PACKAGE, TEXT("LevelSequence"), true);
	return InSequence != nullptr && LevelSequenceClass != nullptr && InSequence->GetClass()->IsChildOf(LevelSequenceClass);
}

void FMovieSceneAkAudioEventTrackEditor::BuildTrackContextMenu(FMenuBuilder& MenuBuilder, UMovieSceneTrack* Track)
{
	auto AkAudioEventTrack = Cast<UMovieSceneAkAudioEventTrack>(Track);

    MenuBuilder.BeginSection("Audiokinetic", LOCTEXT("AKMenu", "Audiokinetic"));
    {
        MenuBuilder.AddMenuEntry(
            LOCTEXT("RefreshAllWaveforms", "Save Wwise project and refresh all sections"),
            LOCTEXT("RefreshAllWaveformsTooltip", "Saves the Wwise project, generates required soundbanks for all sections and refreshes all waveforms."),
            FSlateIcon(),
            FUIAction(
                FExecuteAction::CreateLambda([=] { CreateGenerateSoundbanksWindowForAllSections(Track); }),
                FCanExecuteAction::CreateLambda([=] 
                { 
                    auto aSections = Track->GetAllSections();
                    if (aSections.Num() <= 0)
                        return false;
                    for (auto pSection : aSections)
                    {
                        UMovieSceneAkAudioEventSection* pAkEventSection = dynamic_cast<UMovieSceneAkAudioEventSection*>(pSection);
                        if (pAkEventSection != nullptr)
                        {
                            return true;
                        }
                    }
                    return false;
                })
            )
        );
    }
    MenuBuilder.EndSection();//Audiokinetic
}

/** Creates a soundbank generation window. 
 *  Iterates through all of the sections in the track and adds their required banks to the selected banks in the window.
 */
void FMovieSceneAkAudioEventTrackEditor::CreateGenerateSoundbanksWindowForAllSections(UMovieSceneTrack* in_pTrack)
{
    UMovieSceneAkAudioEventTrack* pAkEventTrack = dynamic_cast<UMovieSceneAkAudioEventTrack*>(in_pTrack);
    if (pAkEventTrack != nullptr)
    {
        TArray<TWeakObjectPtr<UAkAudioBank>> aSoundBanks;
        auto akEventSections = pAkEventTrack->GetAllSections();
        for (auto pSection : akEventSections)
        {
            UMovieSceneAkAudioEventSection* pAkEventSection = dynamic_cast<UMovieSceneAkAudioEventSection*>(pSection);
            if (pAkEventSection != nullptr)
            {
            }
        }
		if (aSoundBanks.Num() > 0)
		{
			AkAudioBankGenerationHelper::CreateGenerateSoundDataWindow(&aSoundBanks, true);
		}
    }
    
}

TSharedRef<ISequencerSection> FMovieSceneAkAudioEventTrackEditor::MakeSectionInterface(UMovieSceneSection& SectionObject, UMovieSceneTrack& Track, FGuid ObjectBinding)
{
	return MakeShareable(new FMovieSceneAkAudioEventSection(SectionObject, GetSequencer()));
}

bool FMovieSceneAkAudioEventTrackEditor::HandleAssetAdded(UObject* Asset, const FGuid& TargetObjectGuid)
{
	if (Asset->IsA<UAkAudioEvent>())
	{
		if (!SupportsSequence(GetMovieSceneSequence()))
		{
			UE_LOG(LogMovieScene, Warning, TEXT("AkAudioEventTrack only supports Level Sequences"));
			return false;
		}

		auto Event = Cast<UAkAudioEvent>(Asset);

		if (TargetObjectGuid.IsValid())
		{
			TArray<TWeakObjectPtr<UObject>> ObjectsToAttachTo;
			for (TWeakObjectPtr<> Object : GetSequencer()->FindObjectsInCurrentSequence(TargetObjectGuid))
				ObjectsToAttachTo.Add(Object);

			auto AddNewAttachedSound = [Event, ObjectsToAttachTo, this](FFrameNumber KeyTime)
			{
				bool bHandleCreated = false;
				bool bTrackCreated = false;
				bool bTrackModified = false;

				for (int32 ObjectIndex = 0; ObjectIndex < ObjectsToAttachTo.Num(); ++ObjectIndex)
				{
					UObject* Object = ObjectsToAttachTo[ObjectIndex].Get();

					FFindOrCreateHandleResult HandleResult = FindOrCreateHandleToObject(Object);
					FGuid ObjectHandle = HandleResult.Handle;
					bHandleCreated |= HandleResult.bWasCreated;

					if (ObjectHandle.IsValid())
					{
						FFindOrCreateTrackResult TrackResult = FindOrCreateTrackForObject(ObjectHandle, UMovieSceneAkAudioEventTrack::StaticClass());
						bTrackCreated |= TrackResult.bWasCreated;

						if (ensure(TrackResult.Track))
						{
							auto AudioTrack = Cast<UMovieSceneAkAudioEventTrack>(TrackResult.Track);
							AudioTrack->AddNewEvent(KeyTime, Event);
							bTrackModified = true;
						}
					}
				}

				FKeyPropertyResult Result;
				Result.bTrackModified = bTrackModified;
				Result.bHandleCreated = bHandleCreated;
				Result.bTrackCreated = bTrackCreated;
				return Result;
			};

			AnimatablePropertyChanged(FOnKeyProperty::CreateLambda(AddNewAttachedSound));
		}
		else
	    {
			auto AddNewMasterSound = [Event, this](FFrameNumber KeyTime)
		    {
				auto TrackResult = FindOrCreateMasterTrack<UMovieSceneAkAudioEventTrack>();
                UMovieSceneTrack* Track = TrackResult.Track;

                auto AkEventTrack = Cast<UMovieSceneAkAudioEventTrack>(Track);
				AkEventTrack->AddNewEvent(KeyTime, Event);
				FKeyPropertyResult Result;
                Result.bTrackCreated = TrackResult.bWasCreated;
                Result.bTrackModified = true;
				return Result;
			};

			AnimatablePropertyChanged(FOnKeyProperty::CreateLambda(AddNewMasterSound));
		}

		return true;
	}
	return false;
}


const FSlateBrush* FMovieSceneAkAudioEventTrackEditor::GetIconBrush() const
{
	return FAkAudioStyle::Get().GetBrush("AudiokineticTools.EventIcon");
}

void FMovieSceneAkAudioEventTrackEditor::BuildAddTrackMenu(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.AddMenuEntry(
		LOCTEXT("AddAkAudioEventTrack", "AkAudioEvent"),
		LOCTEXT("AddAkAudioEventMasterTrackTooltip", "Adds a master AkAudioEvent track."),
		FSlateIcon(FAkAudioStyle::GetStyleSetName(), "AudiokineticTools.EventIcon"),
		FUIAction(FExecuteAction::CreateLambda([=]
		{
			auto FocusedMovieScene = GetFocusedMovieScene();

			if (FocusedMovieScene == nullptr)
			{
				return;
			}

			const FScopedTransaction Transaction(LOCTEXT("AddAkAudioEventMasterTrack_Transaction", "Add master AkAudioEvent Track"));
			FocusedMovieScene->Modify();

			auto NewTrack = FocusedMovieScene->AddMasterTrack<UMovieSceneAkAudioEventTrack>();
			ensure(NewTrack);
			NewTrack->SetIsAMasterTrack(true);

			GetSequencer()->NotifyMovieSceneDataChanged(EMovieSceneDataChangeType::MovieSceneStructureItemAdded);
		}))
	);
}

TSharedPtr<SWidget> FMovieSceneAkAudioEventTrackEditor::BuildOutlinerEditWidget(const FGuid& ObjectBinding, UMovieSceneTrack* Track, const FBuildEditWidgetParams& Params)
{
	// Create a container edit box
	return SNew(SHorizontalBox)

		// Add the audio combo box
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		[
#if UE_4_22_OR_LATER
			FSequencerUtilities::MakeAddButton(LOCTEXT("AudioText", "AkAudioEvent"), FOnGetContent::CreateSP(this, &FMovieSceneAkAudioEventTrackEditor::BuildAudioSubMenu, Track), Params.NodeIsHovered, GetSequencer())
#else
			FSequencerUtilities::MakeAddButton(LOCTEXT("AudioText", "AkAudioEvent"), FOnGetContent::CreateSP(this, &FMovieSceneAkAudioEventTrackEditor::BuildAudioSubMenu, Track), Params.NodeIsHovered)
#endif
		];
}

TSharedRef<SWidget> FMovieSceneAkAudioEventTrackEditor::BuildAudioSubMenu(UMovieSceneTrack* Track)
{
	static const FName AssetRegistryModuleName = TEXT("AssetRegistry");
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(AssetRegistryModuleName);
	TArray<FName> ClassNames;
	ClassNames.Add(UAkAudioEvent::StaticClass()->GetFName());
	TSet<FName> DerivedClassNames;
	AssetRegistryModule.Get().GetDerivedClassNames(ClassNames, TSet<FName>(), DerivedClassNames);

	FMenuBuilder MenuBuilder(true, nullptr);

	FAssetPickerConfig AssetPickerConfig;
	{
		AssetPickerConfig.OnAssetSelected = FOnAssetSelected::CreateRaw(this, &FMovieSceneAkAudioEventTrackEditor::OnAudioAssetSelected, Track);
		AssetPickerConfig.bAllowNullSelection = true;
		AssetPickerConfig.InitialAssetViewType = EAssetViewType::List;
		for (auto ClassName : DerivedClassNames)
		{
			AssetPickerConfig.Filter.ClassNames.Add(ClassName);
		}
	}

	FContentBrowserModule& ContentBrowserModule = FModuleManager::Get().LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));

	TSharedPtr<SBox> MenuEntry = SNew(SBox)
		.WidthOverride(300.0f)
		.HeightOverride(300.f)
		[
			ContentBrowserModule.Get().CreateAssetPicker(AssetPickerConfig)
		];

	MenuBuilder.AddWidget(MenuEntry.ToSharedRef(), FText::GetEmpty(), true);

	return MenuBuilder.MakeWidget();
}


void FMovieSceneAkAudioEventTrackEditor::OnAudioAssetSelected(const FAssetData& AssetData, UMovieSceneTrack* Track)
{
	FSlateApplication::Get().DismissAllMenus();

	const FScopedTransaction Transaction(LOCTEXT("AddAkAudioEvent_Transaction", "Add AkAudioEvent"));

	Track->Modify();
	FFrameNumber KeyTime = GetSequencer()->GetGlobalTime().Time.FrameNumber;
	auto AudioTrack = Cast<UMovieSceneAkAudioEventTrack>(Track);

	UAkAudioEvent* NewEvent = Cast<UAkAudioEvent>(AssetData.GetAsset());
	AudioTrack->AddNewEvent(KeyTime, NewEvent);
	GetSequencer()->NotifyMovieSceneDataChanged(EMovieSceneDataChangeType::MovieSceneStructureItemAdded);
}

#if UE_4_23_OR_LATER
void FMovieSceneAkAudioEventTrackEditor::BuildObjectBindingTrackMenu(FMenuBuilder& MenuBuilder, const TArray<FGuid>& ObjectBindings, const UClass* ObjectClass)
{
	auto ObjectBinding = ObjectBindings[0];
#else
void FMovieSceneAkAudioEventTrackEditor::BuildObjectBindingTrackMenu(FMenuBuilder& MenuBuilder, const FGuid& ObjectBinding, const UClass* ObjectClass)
{
#endif
	if (ObjectClass->IsChildOf(AActor::StaticClass()) || ObjectClass->IsChildOf(USceneComponent::StaticClass()))
	{
		MenuBuilder.AddMenuEntry(
			LOCTEXT("AddAkAudioEventTrack", "AkAudioEvent"),
			LOCTEXT("AddAkAudioEventTrackTooltip", "Adds an AkAudioEvent track."),
			FSlateIcon(FAkAudioStyle::GetStyleSetName(), "AudiokineticTools.EventIcon"),
			FUIAction(FExecuteAction::CreateLambda([=]
			{
				auto FocusedMovieScene = GetFocusedMovieScene();

				if (FocusedMovieScene == nullptr)
				{
					return;
				}

				const FScopedTransaction Transaction(LOCTEXT("AddAkAudioEventTrack_Transaction", "Add AkAudioEvent Track"));
				FocusedMovieScene->Modify();

				auto NewTrack = FocusedMovieScene->AddTrack<UMovieSceneAkAudioEventTrack>(ObjectBinding);
				ensure(NewTrack);

				GetSequencer()->NotifyMovieSceneDataChanged(EMovieSceneDataChangeType::MovieSceneStructureItemAdded);
			}))
		);
	}
}

#undef LOCTEXT_NAMESPACE
